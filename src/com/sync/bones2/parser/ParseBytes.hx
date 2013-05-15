package com.sync.bones2.parser;

import com.sync.bones2.visual.BonesManager;
import nme.display.BitmapData;
import nme.utils.ByteArray;

/** 
 * @author Sync
 */

class ParseBytes {

    public var alias:BonesAlias;
    public var atlas:BonesAtlas;
    public var armatures:BonesArmature;
    public var bonesManager:BonesManager;
    private var _ba:ByteArray;
    private var _bitmap:BitmapData;
    
    public function new(byteArray:ByteArray,texture:BitmapData) {
      _ba = byteArray;
      _bitmap = texture;
      _parse();
    }
    
    private function _parse() {
      _ba.position = 0;
      var alias:ByteArray = new ByteArray();
      var atlas:ByteArray = new ByteArray();
      var armatures:ByteArray = new ByteArray();
      var aliasLength:Int = _ba.readInt();            
      alias.writeBytes(_ba, 4, aliasLength);      
      _ba.position = aliasLength+4;
      var atlasLength:Int = _ba.readInt();            
      atlas.writeBytes(_ba, 4 + 4 + aliasLength, atlasLength);      
      _ba.position = 4 + 4 + aliasLength + atlasLength;
      var armaturesLength:Int = _ba.readInt();
      armatures.writeBytes(_ba, _ba.position, armaturesLength);      
      this.alias = new BonesAlias(alias);
      this.atlas = new BonesAtlas(atlas);
      this.armatures = new BonesArmature(armatures);
      this.bonesManager = new BonesManager(this.alias, this.atlas, this._bitmap);      
    }
    
}