package com.sync.xmlclonverter;
import nme.utils.ByteArray;
import nme.Vector;

/**
 * ...
 * @author Sync
 */
class ByteMatrix
{
    private var _matrix:Vector<Int>;
    private var _bytes:ByteArray;    
    private var _index:Int;

    public function new(atlas:Int, index:Int, x:String, y:String, skewX:String, skewY:String, scaleX:String, scaleY:String, pivotX:String, pivotY:String, z:String) {
      _matrix = new Vector<Int>();      
      _matrix[0] = Std.int(1000 * Std.parseFloat(x));      
      _matrix[1] = Std.int(1000 * Std.parseFloat(y));      
      _matrix[2] = Std.int(1000 * Std.parseFloat(skewX));      
      _matrix[3] = Std.int(1000 * Std.parseFloat(skewY));      
      _matrix[4] = Std.int(1000 * Std.parseFloat(scaleX));      
      _matrix[5] = Std.int(1000 * Std.parseFloat(scaleY));      
      _matrix[6] = Std.int(1000 * Std.parseFloat(pivotX));      
      _matrix[7] = Std.int(1000 * Std.parseFloat(pivotY));      
      _matrix[8] = Std.parseInt(z);
      //Index in Movies
      _index = index;
      //Save data
      _bytes = new ByteArray();
      for(i in 0..._matrix.length)
        _bytes.writeInt(_matrix[i]);
      //Writing bone atlas index
      _bytes.writeInt(atlas);
    }
    
    public function getBytes():ByteArray {
      return _bytes;  
    }
        
}