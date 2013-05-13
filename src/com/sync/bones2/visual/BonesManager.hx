package com.sync.bones2.visual;
import com.sync.bones2.parser.BonesAlias;
import com.sync.bones2.parser.BonesAtlas;
import nme.display.BitmapData;
import nme.Vector;

/** 
 * @author Sync
 */
class BonesManager {

    public var bones:Vector<Bone>;
    private var _alias:BonesAlias;
    private var _atlas:BonesAtlas;
    private var _bitmap:BitmapData;
    
    public function new(alias:BonesAlias,atlas:BonesAtlas,texture:BitmapData) {
      _alias = alias;
      _atlas = atlas;
      _bitmap = texture;
      createBones();
    }
    
    private function createBones() {
      var result:Vector<Bone> = new Vector<Bone>();
      var names:Vector<String> = _alias.getNames();
      var index:Int;
      for (index in 0...names.length) {
        var coords:Vector<Int> = _atlas.getBoneAtlas(index);
        var bone:Bone = new Bone(index, _bitmap, coords);
        result.push(bone);
      }
      bones = result;
    }
    
}