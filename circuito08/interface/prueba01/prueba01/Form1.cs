using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace prueba01
{
    public partial class COM : Form
    {
        
        string recibido;
        public COM()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void COM_Load(object sender, EventArgs e)
        {
            //se inicializa el puerto serie
            string[] ports = SerialPort.GetPortNames();
            //se habilita el cmbPuerto para desplegar opciones
            cmbPuerto.Items.AddRange(ports);
            cmbPuerto.SelectedIndex = 0;
            btnDesconectar.Enabled = false;
            //truco para imprimir
            
            
        }

        private void btnConectar_Click(object sender, EventArgs e)
        {
            btnConectar.Enabled = false;
            btnDesconectar.Enabled = true;
            try
            {
                puertoSerie.PortName = cmbPuerto.Text;
                puertoSerie.Open();

            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message,"Message",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
        }

        private void btnEnviar_Click(object sender, EventArgs e)
        {
            try
            {
                if (puertoSerie.IsOpen)
                { 
                    puertoSerie.WriteLine(txbEnviar.Text+Environment.NewLine);
                    txbEnviar.Clear();
                    
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnDesconectar_Click(object sender, EventArgs e)
        {
            btnConectar.Enabled = true;
            btnDesconectar.Enabled = false;
            try
            {
                
                puertoSerie.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void txbRespuesta_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void puertoSerie_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            while (puertoSerie.IsOpen)
            {
                try
                {
                    recibido = puertoSerie.ReadLine();
                    txbRespuesta.Invoke(new MethodInvoker(delegate { txbRespuesta.Text = recibido; }));

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }


        }


    }
}
