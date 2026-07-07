using System;
using System.Collections.Generic;
using Excel = Microsoft.Office.Interop.Excel;
using Word = Microsoft.Office.Interop.Word;

public class Account
{
    public int ID
    {
        get;
        set;
    }

    public double Balance
    {
        get;
        set;
    }
}

class Program
{
    static void Main()
    {
        var bankAccounts = new List<Account>
        {
            new Account
            {
                ID = 345678,
                Balance = 541.27
            },
            new Account
            {
                ID = 1230221,
                Balance = -127.44
            }
        };

        DisplayInExcel(bankAccounts);
        CreateIconInWordDoc();

        Console.WriteLine("Excel 和 Word 已创建。");
    }

    static void DisplayInExcel(IEnumerable<Account> accounts)
    {
        var excelApp = new Excel.Application();
        excelApp.Visible = true;

        excelApp.Workbooks.Add();

        Excel._Worksheet workSheet =
            (Excel.Worksheet)excelApp.ActiveSheet;

        workSheet.Cells[1, "A"] = "ID Number";
        workSheet.Cells[1, "B"] = "Current Balance";

        int row = 1;

        foreach (var account in accounts)
        {
            row++;
            workSheet.Cells[row, "A"] = account.ID;
            workSheet.Cells[row, "B"] = account.Balance;
        }

        ((Excel.Range)workSheet.Columns[1]).AutoFit();
        ((Excel.Range)workSheet.Columns[2]).AutoFit();

        workSheet.Range["A1:B3"].Copy();
    }

    static void CreateIconInWordDoc()
    {
        var wordApp = new Word.Application();
        wordApp.Visible = true;

        wordApp.Documents.Add();

        wordApp.Selection.PasteSpecial(
            Link: true,
            DisplayAsIcon: true
        );
    }
}