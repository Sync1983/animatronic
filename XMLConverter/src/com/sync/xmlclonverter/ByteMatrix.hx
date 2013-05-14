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

    public function new() {
      _matrix = new Vector<Int>(9);
      _bytes = new ByteArray();
    }
    
    public function getBytes():ByteArray {
      _bytes.clear();
      for(i in 0..._matrix.length)
        _bytes.writeInt(_matrix[i]);
    }
    
    public function addSkew(skewX:Float, skewY:Float):Void {
      _matrix[0] =  _matrix[4] = Std.int(Math.cos(skewX) * 1000);
      _matrix[3] =  - _matrix[4] = Std.int(Math.sin(skewY) * 1000);
    }
    
}