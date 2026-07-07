using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyWinform
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string text = textBox1.Text.Trim();
            if (text != "请输入文本")
            {
                listBox1.Items.Add(text);
                textBox1.Clear();
                textBox1.Focus();
            }
        }

        private void ucBtnExt1_BtnClick(object sender, EventArgs e)
        {
            string text = ucTextBoxEx1.InputText.Trim();
            if (text != "请输入文本")
            {
                listBox1.Items.Add(text);
                ucTextBoxEx1.Focus();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void ucTextBoxEx1_TextChanged(object sender, EventArgs e)
        {

        }

        private void ucBtnExt2_BtnClick(object sender, EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();
            colorDialog.AllowFullOpen = true;
            colorDialog.FullOpen = true;
            colorDialog.AnyColor = true;
            if (colorDialog.ShowDialog() == DialogResult.OK)
            {
                this.BackColor = colorDialog.Color;
            }
        }
    }
}
