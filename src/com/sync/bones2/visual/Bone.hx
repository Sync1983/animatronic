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

class Bone {
  
    private var _id:Int;
    private var _bitmap:BitmapData;
    
    public function new(index:Int, texture:BitmapData, coords:Vector<Int>) {
      if (coords==null)
        return;
      var rect:Rectangle = new Rectangle(coords[BonesAtlas.X], coords[BonesAtlas.Y], coords[BonesAtlas.W], coords[BonesAtlas.H]);
      var point:Point = new Point();
      _bitmap = new BitmapData(Std.int(rect.width),Std.int(rect.height));
      _bitmap.copyPixels(texture, rect, point);  
      point = null;
      rect = null;
    }
    
    public function addToStage(x:Int, y:Int, stage:Stage) {
      var bmp:Bitmap = new Bitmap(_bitmap);
      bmp.x = x;
      bmp.y = y;
      stage.addChild(bmp);
    }
    
}