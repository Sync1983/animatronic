package com.sync.bones2.visual;
import com.sync.bones2.parser.BonesAtlas;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Stage;
import nme.geom.Point;
import nme.geom.Rectangle;
import nme.Vector;

/** 
 * @author Sync
 */

typedef BoneData = Array<Float>;

class Bone {
  
    public static var X       :Int = 0;
    public static var Y       :Int = 1;
    public static var skewX   :Int = 2;
    public static var skewY   :Int = 3;
    public static var scaleX  :Int = 4;
    public static var scaleY  :Int = 5;
    public static var pivotX  :Int = 6;
    public static var pivotY  :Int = 7;
    public static var z       :Int = 8;
  
    private var _id:Int;
    private var _bitmap:BitmapData;
    private var _bmp:Bitmap;
    
    public function new(index:Int, texture:BitmapData, coords:Vector<Int>) {
      if (coords==null)
        return;
      var rect:Rectangle = new Rectangle(coords[BonesAtlas.X], coords[BonesAtlas.Y], coords[BonesAtlas.W], coords[BonesAtlas.H]);
      var point:Point = new Point();
      _bitmap = new BitmapData(Std.int(rect.width),Std.int(rect.height));
      _bitmap.copyPixels(texture, rect, point);
      _bmp = new Bitmap(_bitmap);
      point = null;
      rect = null;
    }
    
    public function setupMatrix(boneData:BoneData):Void {
      _bmp.x = boneData[Bone.X] - boneData[Bone.pivotX];          
      _bmp.y = boneData[Bone.Y] - boneData[Bone.pivotY];
      _bmp.rotation = boneData[Bone.skewY];
      _bmp.scaleX = boneData[Bone.scaleX];
      _bmp.scaleY = boneData[Bone.scaleY];
      _bmp.x += 200;
      _bmp.y += 220;
    }
    
    public function addToStage(x:Int, y:Int, stage:Stage) {
      stage.addChild(_bmp);
    }
    
}