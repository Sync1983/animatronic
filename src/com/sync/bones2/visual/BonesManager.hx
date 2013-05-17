package com.sync.bones2.visual;
import com.sync.bones2.parser.BonesAlias;
import com.sync.bones2.parser.BonesArmature;
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
    private var _armatures:BonesArmature;
    private var _bitmap:BitmapData;
    
    public function new(alias:BonesAlias,atlas:BonesAtlas,texture:BitmapData,armatures:BonesArmature) {
      _alias = alias;
      _atlas = atlas;
      _bitmap = texture;
      _armatures = armatures;
      createBones();
    }
    
    private function createBones() {      
      var names:Vector<String> = _alias.getNames();
      var itemsCount:Int = names.length;
      var result:Array<Bone> = new Array<Bone>();
      
      for (index in 0...itemsCount) {
        var coords:Vector<Int> = _atlas.getBoneAtlas(index);
        var bone:Bone = new Bone(index, _bitmap, coords);
        bone.setupMatrix(_armatures.getBoneParams(index));
        trace("Name: " + names[index] + _armatures.getBoneParams(index));
        result[itemsCount-index-1] = bone;
      }
      bones = result;
    }
    
}