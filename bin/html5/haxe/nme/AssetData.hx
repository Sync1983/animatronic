package nme;


import nme.Assets;


class AssetData {

	
	public static var className = new Map <String, Dynamic> ();
	public static var library = new Map <String, LibraryType> ();
	public static var path = new Map <String, String> ();
	public static var type = new Map <String, AssetType> ();
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			path.set ("assets/bins/binary.bin", "assets/bins/binary.bin");
			type.set ("assets/bins/binary.bin", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("assets/img/Vikasa_output.png", "assets/img/Vikasa_output.png");
			type.set ("assets/img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/Vikasa_output.png", "img/Vikasa_output.png");
			type.set ("img/Vikasa_output.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("bins/binary.bin", "bins/binary.bin");
			type.set ("bins/binary.bin", Reflect.field (AssetType, "binary".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}






