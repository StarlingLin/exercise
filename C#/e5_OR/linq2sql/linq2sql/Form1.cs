using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace linq2sql
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            DataClasses1DataContext dc = new DataClasses1DataContext();

            var results = from emp in dc.Person
                          where emp is Employee
                          select emp;

            foreach (Employee emp in results)
            {
                listBox1.Items.Add(emp.LastName);
            }
        }
    }
}
