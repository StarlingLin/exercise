using System;
using System.Linq;
using System.Xml.Linq;

XElement root = new XElement("Students",
    new XElement("Student",
        new XAttribute("Id", 1),
        new XElement("Name", "张三"),
        new XElement("Age", 20),
        new XElement("Major", "软件工程")
    ),
    new XElement("Student",
        new XAttribute("Id", 2),
        new XElement("Name", "李四"),
        new XElement("Age", 22),
        new XElement("Major", "计算机科学")
    )
);

var student = root.Elements("Student")
    .First(s => (string?)s.Attribute("Id") == "1");

student.SetAttributeValue("Id", 100);

Console.WriteLine(root);