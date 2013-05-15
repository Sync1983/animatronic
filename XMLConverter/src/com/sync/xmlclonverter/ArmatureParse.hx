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
  private var _namesMap:Array<String>;
  private var _atlas:AtlasParse;
  private var _armatures:ByteArray;

  public function new(part:Xml,atlasObj:AtlasParse) {    
    this._xmlPart = part;
    _atlas = atlasObj;
    part = null;    
    this._name = this._xmlPart.get('name'); 
    this._frameRate = Std.parseInt(this._xmlPart.get('frameRate'));    
    this._namesMap = new Array<String>();
    
    var armatures:Iterator<Xml> = this._xmlPart.firstElement().elements(); 
    
    _armatures = new ByteArray();
    //Write frameRate and name for armatures animation
    _armatures.writeInt(_frameRate);
    _armatures.writeUTF(_name);
    //Write all armatures first state struct
    for (armature in armatures) {
      var ba:ByteArray = parseArmature(armature);
      _armatures.writeInt(ba.length);
      _armatures.writeBytes(ba);    
    }
  }
  
  public function getBytes():ByteArray {
    return _armatures;
  }
  
  function parseArmature(armature:Xml):ByteArray {
    var res:ByteArray = new ByteArray();
    var name:String = armature.get('name');
    //Write armature name
    res.writeUTF(name);
    
    for (bone in armature.elements()) {
      var atlas:Int = Lambda.indexOf(_atlas.alias,bone.firstElement().get('name'));
      var name:String = bone.get('name');
      
      var index:Int;
      if (!Lambda.has(_namesMap,name))
        _namesMap.push(name);
      index = Lambda.indexOf(_namesMap,name);
        
      var X:String = bone.get('x');
      var Y:String = bone.get('y');
      var skewX:String = bone.get('kX');
      var skewY:String = bone.get('kY');
      var scaleX:String = bone.get('cX');
      var scaleY:String = bone.get('cY');
      var pivotX:String = bone.get('pX');
      var pivotY:String = bone.get('pY');
      var z:String = bone.get('z');      
      
      var matrix:ByteMatrix = new ByteMatrix(atlas, index, X, Y, skewX, skewY, scaleX, scaleY, pivotX, pivotY, z);
      res.writeBytes(matrix.getBytes());
    }        
    return res;
  }
  
  
  
  private function parse():Void {    
    
  }
  
      
}

