package com.sync.bones2;

import com.sync.bones2.parser.ParseBytes;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Sprite;
import nme.events.Event;
import nme.Lib;
import nme.utils.ByteArray;

/** 
 * @author Sync
 */

class Main extends Sprite 
{
	var inited:Bool;
  var img:BitmapData;
  var ba:ByteArray;

	/* ENTRY POINT */
	
	function resize(e) 
	{
		if (!inited) init();
		// else (resize or orientation change)
	}
	
	function init() 
	{
		if (inited) return;
		inited = true;

		img = Assets.getBitmapData('img/Vikasa_output.png');
    //stage.addChild(new Bitmap(img));
    ba = Assets.getBytes('bins/binary.bin');
  
    var parser:com.sync.bones2.parser.ParseBytes = new com.sync.bones2.parser.ParseBytes(ba, img);
    for (index in 0...parser.bonesManager.bones.length) {      
      parser.bonesManager.bones[index].addToStage(0,0,stage);
    }
    
	}

	

	public function new() 
	{
		super();	
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	function added(e) 
	{
		removeEventListener(Event.ADDED_TO_STAGE, added);
		stage.addEventListener(Event.RESIZE, resize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}
	
	public static function main() 
	{
		// static entry point
		Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		Lib.current.addChild(new Main());
	}
}
