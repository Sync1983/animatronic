package com.sync.xmlclonverter;

/** 
 * @author Sync
 */

class Bone
{
    private var _assetName:String;
    private var _boneName:String;
    private var _startPosition:Array<Int>;
    private var _movies:Array<String>;
    private var _moviesData:Map < String, Array<Int> > ;
    private var _atlas:Xml;
    private var _scelet:Xml;

    public function new(assetName:String,atlas:Xml,scelet:Xml) {
      _assetName = assetName;
      _atlas = atlas;
      _scelet = scelet;
      _startPosition = new Array<Int>();
      _movies = new Array<String>();
      _moviesData = new Map < String, Array<Int> > ();      
      parseBoneData();
    }
    
    function parseBoneData() {
        
    }
    
}