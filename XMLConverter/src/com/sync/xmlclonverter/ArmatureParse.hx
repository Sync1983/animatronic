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

  public function new(part:Xml) {    
    this._xmlPart = part;
    part = null;    
    this._name = this._xmlPart.get('name'); 
    this._frameRate = Std.parseInt(this._xmlPart.get('frameRate'));    
    trace(this._name);
    trace(this._frameRate);
    var armatures:Iterator<Xml> = this._xmlPart.firstElement().elements(); 
    for(armature in armatures)
      parseArmature(armature);
  }
  
  function parseArmature(armature:Xml):ByteArray {
    var res:ByteArray = new ByteArray();
    var name:String = armature.get('name');
    trace(name);
    for (bone in armature.elements()) {
      var atlas:String = bone.firstElement().get('name');
      var X:String = bone.get('x');
      var Y:String = bone.get('y');
      var skewX:String = bone.get('kX');
      var skewY:String = bone.get('kY');
      var scaleX:String = bone.get('cX');
      var scaleY:String = bone.get('cY');
      var pivotX:String = bone.get('pX');
      var pivotY:String = bone.get('pY');
      var z:String = bone.get('z');      
      var matrix:ByteMatrix = new ByteMatrix();
      matrix.addSkew(skewX, skewY);
      
      trace(atlas);
    }    
    return res;
  }
  
  
  
  private function parse():Void {    
    
  }
  
      
}