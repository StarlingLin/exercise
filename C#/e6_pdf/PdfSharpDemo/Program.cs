using System;
using System.IO;
using PdfSharp.Drawing;
using PdfSharp.Fonts;
using PdfSharp.Pdf;

class Program
{
    static void Main()
    {
        GlobalFontSettings.FontResolver = new WindowsFontResolver();

        PdfDocument document = new PdfDocument();
        document.Info.Title = "PDFsharp Demo";

        PdfPage page = document.AddPage();

        XGraphics gfx = XGraphics.FromPdfPage(page);
        XFont font = new XFont("Arial", 20);

        gfx.DrawString(
            "Hello PDFsharp!",
            font,
            XBrushes.Black,
            new XRect(0, 0, page.Width.Point, page.Height.Point),
            XStringFormats.Center
        );

        string filename = "hello.pdf";
        document.Save(filename);

        Console.WriteLine($"PDF 已生成：{Path.GetFullPath(filename)}");
    }
}

public class WindowsFontResolver : IFontResolver
{
    public FontResolverInfo ResolveTypeface(string familyName, bool isBold, bool isItalic)
    {
        return new FontResolverInfo("Arial");
    }

    public byte[] GetFont(string faceName)
    {
        return File.ReadAllBytes(@"C:\Windows\Fonts\arial.ttf");
    }
}