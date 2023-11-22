using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace prueba01
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
              

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void cambiar_Click(object sender, EventArgs e)
        {
            int contadorCero = 0;
            int contadorUno = contadorCero + 1;
            if (contadorUno == 1)
            {
                imprimir.Text = "Yo soy";
                contadorUno = contadorCero + 1;
            }
            else if (contadorUno == 2)
            {
                imprimir.Text = "Una figura";
                contadorUno = contadorCero + 1;
            }
            else if (contadorUno == 3)
            {
                imprimir.Text = "Lalala...";
                contadorUno = contadorCero + 1;
            }
            else if(contadorUno > 3) {
                contadorUno = 0;
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
