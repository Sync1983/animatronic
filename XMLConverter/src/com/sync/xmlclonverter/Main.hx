package com.sync.xmlclonverter;

//import neko.io.File;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Loader;
import nme.display.LoaderInfo;
import nme.display.Sprite;
import nme.events.Event;
import nme.Lib;
import nme.net.URLLoader;
import nme.net.URLRequest;
import nme.utils.ByteArray;

/**
 * ...
 * @author Sync
 */

class Main extends Sprite 
{
	var inited:Bool;
  var image:ByteArray;
  var atlas:Xml;
  var scelet:Xml;

	function init() 
	{
		if (inited) return;
		inited = true;
		
		// Assets:
		atlas   = Xml.parse(Assets.getText("assets/Atlas.xml"));
		scelet  = Xml.parse(Assets.getText("assets/XNLData.xml"));
    /*trace(atlas);
    trace(scelet);
    */
    var atlasObj:AtlasParse = new AtlasParse(atlas);
    var data:ByteArray = atlasObj.parse();
    trace("Atlas length: "+data.length);    
    //File.saveBytes("D:\\dev\\Bones2\\assets\\bins\\binary.bin", data);
    var armatureObj:ArmatureParse = new ArmatureParse(scelet.firstChild());
    /*data = data.firstChild();
    for (arm in data.elements()) {      
      if(arm.nodeName=='armatures') {
      var item:ArmatureParse;      
        for(i in arm.elements()) {
          item = new ArmatureParse(i);          
          var BA:ByteArray = item.pack();          
        }
      }
    }*/
	}
    
  private function onLoaderComplite(event:Event):Void {
    var loader:URLLoader = event.currentTarget;
    loader.removeEventListener(Event.COMPLETE, onLoaderComplite);        
    
    
  }

	/* SETUP */

	public function new() 
	{
		super();	
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	function added(e) 
	{
		removeEventListener(Event.ADDED_TO_STAGE, added);		
		init();		
	}
	
	public static function main() 
	{
		// static entry point
		Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		Lib.current.addChild(new Main());
	}
}
