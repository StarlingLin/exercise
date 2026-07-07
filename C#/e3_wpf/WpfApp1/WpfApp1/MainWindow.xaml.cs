using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using AduSkin.Controls.Metro;

using Forms = System.Windows.Forms;

namespace WpfApp1
{
    public partial class MainWindow : MetroWindow
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ChangeColorButton_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            Forms.ColorDialog colorDialog = new Forms.ColorDialog();

            if (colorDialog.ShowDialog() == Forms.DialogResult.OK)
            {
                Color color = Color.FromArgb(
                    colorDialog.Color.A,
                    colorDialog.Color.R,
                    colorDialog.Color.G,
                    colorDialog.Color.B
                );

                RootGrid.Background = new SolidColorBrush(color);
            }
        }
    }
}