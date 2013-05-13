package com.sync.xmlclonverter;
import haxe.io.Bytes;
import nme.utils.ByteArray;
import nme.Vector;

/**
 * ...
 * @author Sync
 */
class AtlasParse {
  
  private var _xml:Xml;
  private var _name:String;
  public var alias:Vector<String>;

  public function new(xml:Xml) {
    _xml = xml.firstChild();
    _name = _xml.get('name');    
  }
  
  public function parse():ByteArray {
    var atlas:ByteArray = new ByteArray();
    var alias:ByteArray = new ByteArray();
    this.alias = new Vector<String>();
    var item:Int = 0;
    for (sub in _xml.elements()) {
      alias.writeUTF(sub.get('name'));
      //save for next converter work
      this.alias[item] = sub.get('name');
      alias.writeInt(item);
      atlas.writeInt(item);
      atlas.writeInt(Std.parseInt(sub.get('x')));
      atlas.writeInt(Std.parseInt(sub.get('y')));
      atlas.writeInt(Std.parseInt(sub.get('width')));
      atlas.writeInt(Std.parseInt(sub.get('height')));      
      item++;
    }
    var res:ByteArray = new ByteArray();
    //Alias data length
    res.writeInt(alias.length);
    //Alias data
    res.writeBytes(alias);
    //Atlas data length
    res.writeInt(atlas.length);
    //Atlas data
    res.writeBytes(atlas);
    return res;
  }
    
}