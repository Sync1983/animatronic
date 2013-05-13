package com.sync.xmlclonverter;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.utils.ByteArray;
import nme.Vector;

/** 
 * @author Sync
 */

class ArmatureParse {
  
  private var _xmlPart:Xml;
  private var _name:String;
  private var _frameRate:Int;
  private var _bones:Vector<Dynamic>;  
  private static var fields:Array<String> = [ "x", "y", "kX", "kY", "cX", "cY", "pX", "pY", "z","name"];

  public function new(part:Xml) {    
    this._xmlPart = part;
    part = null;    
    this._name = this._xmlPart.get('name'); 
    this._frameRate = Std.parseInt(this._xmlPart.get('frameRate'));    
    trace(this._name);
    trace(this._frameRate);
    var armatures:Xml = this._xmlPart.firstElement();    
    trace(armatures);
  }
  
  private function parse():Void {    
    for (bone in this._xmlPart.elements()) {
      if (bone.nodeName == 'b') {        
        var boneData:Dynamic = {};
        for (field in ArmatureParse.fields)        
          Reflect.setField(boneData, field, bone.get(field));        
        _bones.push(boneData);
      }
    }
    trace(_bones);
  }
  
  public function pack():ByteArray{
    var res:ByteArray = new ByteArray();    
    for (bone in _bones) {      
      var size:Int = Std.string(bone.name).length * 2 + 72;
      //Writing size
      res.writeShort(size);
      //Writing const-length fields
      for (field in ArmatureParse.fields)
        if (field != "name")
          res.writeFloat(Std.parseFloat(Reflect.field(bone, field)));
      var name:String = Reflect.field(bone, "name");
      //Writing name UTF
      res.writeUTFBytes(name);      
    }
    res.writeUTFBytes(_name);
    res.compress();
    return res;
  }
    
}