class ApplicationMain
{

	#if waxe
	static public var frame : wx.Frame;
	static public var autoShowFrame : Bool = true;
	#if nme
	static public var nmeStage : wx.NMEStage;
	#end
	#end
	
	public static function main()
	{
		#if nme
		nme.Lib.setPackage("Sync", "XMLConverter", "com.sync.xmlclonverter.XMLConverter", "1.0.0");
		
		#end
		
		#if waxe
		wx.App.boot(function()
		{
			
			frame = wx.Frame.create(null, null, "XMLConverter", null, { width: 800, height: 480 });
			
			#if nme
			var stage = wx.NMEStage.create(frame, null, null, { width: 800, height: 480 });
			#end
			
			com.sync.xmlclonverter.Main.main();
			
			if (autoShowFrame)
			{
				wx.App.setTopWindow(frame);
				frame.shown = true;
			}
		});
		#else
		
		nme.Lib.create(function()
			{ 
				//if ((800 == 0 && 480 == 0) || false)
				//{
					nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
					nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
				//}
				
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
					#if nme
					if (Std.is (instance, nme.display.DisplayObject)) {
						nme.Lib.current.addChild(cast instance);
					}
					#end
				}
			},
			800, 480, 
			60, 
			0,
			(true ? nme.Lib.HARDWARE : 0) |
			(false ? nme.Lib.ALLOW_SHADERS : 0) |
			(false ? nme.Lib.REQUIRE_SHADERS : 0) |
			(false ? nme.Lib.DEPTH_BUFFER : 0) |
			(false ? nme.Lib.STENCIL_BUFFER : 0) |
			(true ? nme.Lib.RESIZABLE : 0) |
			(false ? nme.Lib.BORDERLESS : 0) |
			(false ? nme.Lib.VSYNC : 0) |
			(false ? nme.Lib.FULLSCREEN : 0) |
			(0 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(0 == 2 ? nme.Lib.HW_AA : 0),
			"XMLConverter"
			
		);
		#end
		
	}
	
	
	#if neko
	public static function __init__ () {
		
		untyped $loader.path = $array ("@executable_path/", $loader.path);
		
	}
	#end
	
	
	public static function getAsset(inName:String):Dynamic
	{
		#if nme
		
		if (inName == "img/Vikasa_output.png")
		{
			
			return nme.Assets.getBitmapData ("img/Vikasa_output.png");
			
		}
		
		if (inName == "assets/Atlas.xml")
		{
			
			return nme.Assets.getText ("assets/Atlas.xml");
			
		}
		
		if (inName == "assets/binary.bin")
		{
			
			return nme.Assets.getText ("assets/binary.bin");
			
		}
		
		if (inName == "assets/img/Vikasa_output.png")
		{
			
			return nme.Assets.getBitmapData ("assets/img/Vikasa_output.png");
			
		}
		
		if (inName == "assets/Vikasa_output")
		{
			
			return nme.Assets.getBytes ("assets/Vikasa_output");
			
		}
		
		if (inName == "assets/XNLData.xml")
		{
			
			return nme.Assets.getText ("assets/XNLData.xml");
			
		}
		
		#end
		return null;
	}
	
	
}
