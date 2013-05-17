package nme;


import nme.Assets;


class AssetData {

	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			path.set ("img/Vikasa_output.png", "img/Vikasa_output.png");
			type.set ("img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/Atlas.xml", "assets/Atlas.xml");
			type.set ("assets/Atlas.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/binary.bin", "assets/binary.bin");
			type.set ("assets/binary.bin", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/img/Vikasa_output.png", "assets/img/Vikasa_output.png");
			type.set ("assets/img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/Vikasa_output", "assets/Vikasa_output");
			type.set ("assets/Vikasa_output", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("assets/XNLData.xml", "assets/XNLData.xml");
			type.set ("assets/XNLData.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}
