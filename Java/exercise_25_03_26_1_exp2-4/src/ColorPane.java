import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ColorPane extends JFrame
{
    public ColorPane()
    {
        setTitle("ColorPane");
        setLayout(new GridLayout(3, 3));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);

        String[] colorNames = {"blue", "cyan", "green", "magenta", "orange", "pink", "red", "white", "yellow"};
        Color[] colors = {Color.BLUE, Color.CYAN, Color.GREEN, Color.MAGENTA, Color.ORANGE, Color.PINK, Color.RED, Color.WHITE, Color.YELLOW};

        for (int i = 0; i < colorNames.length; i++)
        {
            JButton button = new JButton(colorNames[i]);
            button.addActionListener(new ActionListener()
            {
                @Override
                public void actionPerformed(ActionEvent e)
                {
                    JButton source = (JButton) e.getSource();
                    for (int j = 0; j < colorNames.length; j++)
                    {
                        if (source.getText().equals(colorNames[j]))
                        {
                            source.setBackground(colors[j]);
                            break;
                        }
                    }
                }
            });
            add(button);
        }

        setVisible(true);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable()
        {
            public void run()
            {
                new ColorPane();
            }
        });
    }
}
