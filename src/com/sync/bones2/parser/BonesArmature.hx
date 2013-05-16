package com.sync.bones2.parser;
import nme.utils.ByteArray;

/** 
 * @author Sync
 */

class BonesArmature {

    private var _ba:ByteArray;
    
    private var _name:String;
    private var _frameRate:Int;
    
    private var _startPosition:Array<Array<Float>>;
    
    public function new(byteArray:ByteArray) {
      _ba = byteArray;
      _startPosition = new Array<Array<Float>>();
      parse();
    }
    
    public function getBoneParams(atlasId:Int):Array<Float> {
      if ((atlasId<0)||(atlasId>=_startPosition.length))
        return null;
      return _startPosition[atlasId];
    }
    
    function parse() {
      _ba.position = 0; 
      _frameRate = _ba.readInt();
      _name = _ba.readUTF();
      //TODO now this for just once armature!!!
      var armatureLength:Int = _ba.readInt();
      var armatureName:String = _ba.readUTF();      
      trace("Name: " + _name + " FrameRate: " + _frameRate);
      while (_ba.position < _ba.length) {    
        
        var X:      Float = _ba.readInt() / 1000;        
        var Y:      Float = _ba.readInt() / 1000;
        var skewX:  Float = _ba.readInt() / 1000;
        var skewY:  Float = _ba.readInt() / 1000;
        var scaleX: Float = _ba.readInt() / 1000;
        var scaleY: Float = _ba.readInt() / 1000;
        var pivotX: Float = _ba.readInt() / 1000;
        var pivotY: Float = _ba.readInt() / 1000;
        var z:      Float = _ba.readInt();        
        var atlas:  Int   = _ba.readInt();        
        _startPosition[atlas] = [X, Y, skewX, skewY, scaleX, scaleY, pivotX, pivotY, z];
        /*  _matrix[0] = Std.int(100 * Std.parseFloat(x));      
        _matrix[1] = Std.int(100 * Std.parseFloat(y));      
        _matrix[2] = Std.int(100 * Std.parseFloat(skewX));      
        _matrix[3] = Std.int(100 * Std.parseFloat(skewY));      
        _matrix[4] = Std.int(100 * Std.parseFloat(scaleX));      
        _matrix[5] = Std.int(100 * Std.parseFloat(scaleY));      
        _matrix[6] = Std.int(100 * Std.parseFloat(pivotX));      
        _matrix[7] = Std.int(100 * Std.parseFloat(pivotY));  */
      }
     trace("Armature: " + armatureName);
     trace(_startPosition);
    }
    
}