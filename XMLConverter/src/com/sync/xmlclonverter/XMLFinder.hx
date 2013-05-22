package com.sync.xmlclonverter;

/**
 * ...
 * @author Sync
 */
class XMLFinder
{

    public function new() 
    {
        
    }
    
    public static function findNodeNamed(root:Xml,name:String):Xml {
      for (node in root.elements()) {
        var childXml:Xml = findNodeNamed(node, name);
        if (node.nodeName == name)
          return node;
        else if (childXml != null)
          return childXml;
      }
      return null;
    }
    
    public static function findNodeByName(root:Xml,name:String):Xml {
      for (node in root.elements()) {
        var childXml:Xml = findNodeNamed(node, name);
        if (node.get("name") == name)
          return node;
        else if (childXml != null)
          return childXml;
      }
      return null;
    }
    
}