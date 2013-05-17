package com.sync.bones2.parser;
import nme.utils.ByteArray;
import nme.Vector;

/**
 * ...
 * @author Sync
 */
class BonesAtlas
{
    public static var X:Int = 0;
    public static var Y:Int = 1;
    public static var W:Int = 2;
    public static var H:Int = 3;
    
    private var _ba:ByteArray;
    private var _coords:Array<Dynamic>;
    
    public function new(byteArray:ByteArray) {
      _ba = byteArray;
      byteArray = null;
      _coords = new Array<Dynamic>();
      _parse();
    }
    
    public function getBoneAtlas(boneIndex:Int):Array<Int> {      
      if (_coords.length < boneIndex)
        return null;
      return _coords[boneIndex];
    }
    
    function _parse() {
      trace(_ba.length);      
      _ba.position = 0;          
      while (_ba.position < _ba.length) {
        var item:Array<Int> = new Array<Int>();
        var index:Int = _ba.readInt();
        item[BonesAtlas.X] = _ba.readInt();
        item[BonesAtlas.Y] = _ba.readInt();
        item[BonesAtlas.W] = _ba.readInt();
        item[BonesAtlas.H] = _ba.readInt();         
        _coords[index] = item;
      }      
    }
    
}