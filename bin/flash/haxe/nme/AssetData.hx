package nme;


import nme.Assets;


class AssetData {

	
	public static var className = new #if haxe3 Map <String, #else Hash <#end Dynamic> ();
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			className.set ("assets/bins/binary.bin", nme.NME_assets_bins_binary_bin);
			type.set ("assets/bins/binary.bin", Reflect.field (AssetType, "binary".toUpperCase ()));
			className.set ("assets/img/Vikasa_output.png", nme.NME_assets_img_vikasa_output_png);
			type.set ("assets/img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			className.set ("img/Vikasa_output.png", nme.NME_img_vikasa_output_png);
			type.set ("img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			className.set ("bins/binary.bin", nme.NME_bins_binary_bin);
			type.set ("bins/binary.bin", Reflect.field (AssetType, "binary".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}


class NME_assets_bins_binary_bin extends nme.utils.ByteArray { }
class NME_assets_img_vikasa_output_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_img_vikasa_output_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_bins_binary_bin extends nme.utils.ByteArray { }
