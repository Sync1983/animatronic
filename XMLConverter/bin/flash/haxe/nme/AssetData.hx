package nme;


import nme.Assets;


class AssetData {

	
	public static var className = new #if haxe3 Map <String, #else Hash <#end Dynamic> ();
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			className.set ("img/Vikasa_output.png", nme.NME_img_vikasa_output_png);
			type.set ("img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			className.set ("assets/Atlas.xml", nme.NME_assets_atlas_xml);
			type.set ("assets/Atlas.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			className.set ("assets/binary.bin", nme.NME_assets_binary_bin);
			type.set ("assets/binary.bin", Reflect.field (AssetType, "text".toUpperCase ()));
			className.set ("assets/img/Vikasa_output.png", nme.NME_assets_img_vikasa_output_png);
			type.set ("assets/img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			className.set ("assets/Vikasa_output", nme.NME_assets_vikasa_output);
			type.set ("assets/Vikasa_output", Reflect.field (AssetType, "binary".toUpperCase ()));
			className.set ("assets/XNLData.xml", nme.NME_assets_xnldata_xml);
			type.set ("assets/XNLData.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}


class NME_img_vikasa_output_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_atlas_xml extends nme.utils.ByteArray { }
class NME_assets_binary_bin extends nme.utils.ByteArray { }
class NME_assets_img_vikasa_output_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_vikasa_output extends nme.utils.ByteArray { }
class NME_assets_xnldata_xml extends nme.utils.ByteArray { }
