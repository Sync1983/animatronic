#if nme

import com.sync.xmlclonverter.Main;
import nme.Assets;
import nme.events.Event;


class ApplicationMain {
	
	static var mPreloader:NMEPreloader;

	public static function main () {
		
		var call_real = true;
		
		
		var loaded:Int = nme.Lib.current.loaderInfo.bytesLoaded;
		var total:Int = nme.Lib.current.loaderInfo.bytesTotal;
		
		nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
		nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		
		if (loaded < total || true) /* Always wait for event */ {
			
			call_real = false;
			mPreloader = new NMEPreloader();
			nme.Lib.current.addChild(mPreloader);
			mPreloader.onInit();
			mPreloader.onUpdate(loaded,total);
			nme.Lib.current.addEventListener (nme.events.Event.ENTER_FRAME, onEnter);
			
		}
		
		
		#if !fdb
		haxe.Log.trace = flashTrace;
		#end
		
		if (call_real)
			begin ();
	}

	#if !fdb
	private static function flashTrace( v : Dynamic, ?pos : haxe.PosInfos ) {
		var className = pos.className.substr(pos.className.lastIndexOf('.') + 1);
		var message = className+"::"+pos.methodName+":"+pos.lineNumber+": " + v;
		
        if (flash.external.ExternalInterface.available)
			flash.external.ExternalInterface.call("console.log", message);
		else untyped flash.Boot.__trace(v, pos);
    }
	#end
	
	private static function begin () {
		
		var hasMain = false;
		
		for (methodName in Type.getClassFields(com.sync.xmlclonverter.Main))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (com.sync.xmlclonverter.Main, Reflect.field (com.sync.xmlclonverter.Main, "main"), []);
		}
		else
		{
			var instance = Type.createInstance(com.sync.xmlclonverter.Main, []);
			if (Std.is (instance, nme.display.DisplayObject)) {
				nme.Lib.current.addChild(cast instance);
			}	
		}
		
	}

	static function onEnter (_) {
		
		var loaded = nme.Lib.current.loaderInfo.bytesLoaded;
		var total = nme.Lib.current.loaderInfo.bytesTotal;
		mPreloader.onUpdate(loaded,total);
		
		if (loaded >= total) {
			
			nme.Lib.current.removeEventListener(nme.events.Event.ENTER_FRAME, onEnter);
			mPreloader.addEventListener (Event.COMPLETE, preloader_onComplete);
			mPreloader.onLoaded();
			
		}
		
	}

	public static function getAsset (inName:String):Dynamic {
		
		
		if (inName=="img/Vikasa_output.png")
			 
            return Assets.getBitmapData ("img/Vikasa_output.png");
         
		
		if (inName=="assets/Atlas.xml")
			 
			 return Assets.getText ("assets/Atlas.xml");
         
		
		if (inName=="assets/binary.bin")
			 
			 return Assets.getText ("assets/binary.bin");
         
		
		if (inName=="assets/img/Vikasa_output.png")
			 
            return Assets.getBitmapData ("assets/img/Vikasa_output.png");
         
		
		if (inName=="assets/Vikasa_output")
			 
            return Assets.getBytes ("assets/Vikasa_output");
         
		
		if (inName=="assets/XNLData.xml")
			 
			 return Assets.getText ("assets/XNLData.xml");
         
		
		
		return null;
		
	}
	
	
	private static function preloader_onComplete (event:Event):Void {
		
		mPreloader.removeEventListener (Event.COMPLETE, preloader_onComplete);
		
		nme.Lib.current.removeChild(mPreloader);
		mPreloader = null;
		
		begin ();
		
	}
	
}

class NME_img_vikasa_output_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_atlas_xml extends nme.utils.ByteArray { }
class NME_assets_binary_bin extends nme.utils.ByteArray { }
class NME_assets_img_vikasa_output_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_vikasa_output extends nme.utils.ByteArray { }
class NME_assets_xnldata_xml extends nme.utils.ByteArray { }


#else

import com.sync.xmlclonverter.Main;

class ApplicationMain {
	
	public static function main () {
		
		var hasMain = false;
		
		for (methodName in Type.getClassFields(com.sync.xmlclonverter.Main))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (com.sync.xmlclonverter.Main, Reflect.field (com.sync.xmlclonverter.Main, "main"), []);
		}
		else
		{
			var instance = Type.createInstance(com.sync.xmlclonverter.Main, []);
			if (Std.is (instance, flash.display.DisplayObject)) {
				flash.Lib.current.addChild(cast instance);
			}
		}
		
	}

}

#end
