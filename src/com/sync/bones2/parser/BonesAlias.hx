package com.sync.bones2.parser;
import nme.utils.ByteArray;
import nme.Vector;

/**
 * ...
 * @author Sync
 */
class BonesAlias
{
    private var _ba:ByteArray;
    private var _names:Array<String>;
    
    public function new(byteArray:ByteArray) {
      _ba = byteArray;
      byteArray = null;
      _names = new Array<String>();
      _parse();
    }
    
    public function getNames():Array<String> {
      return _names;
    }
    
    function _parse() {
      _ba.position = 0;      
      while (_ba.position < _ba.length) {        
        var name:String = _ba.readUTF();
        var index:Int = _ba.readInt();
        _names[index] = name;        
      }      
    }    
    
}