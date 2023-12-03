using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//controlar puerto serie
// sing System.Windows.Forms;

namespace InterfazPFinal
{
    public partial class Form1 : Form
    {

        private string strBufferIn;
        private string strBufferOut;
        private string respuesta;

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e) //InstModAut
        {

        }

        private void Form1_Load(object sender, EventArgs e) //serial port
        {
            strBufferIn = "";
            strBufferOut = "";
            //Deshabilitamos botones
            ConectPS.Enabled = false;
            DesconectPS.Enabled = false;
            BtnAuto.Enabled = false;
            BtnManual.Enabled = false;

            //Deshabilitamos paneles que no tienen uso 
            panel2.Enabled = false;
            panel3.Enabled = false;
            panel4.Enabled = false;

            //inicializar puerto serie

            string[] puertosDisponible = SerialPort.GetPortNames();
            //cmbPuerto
            cmbPuerto.Items.AddRange(puertosDisponible);
            //cmbPuerto.SelectedIndex = 0;

            if (cmbPuerto.Items.Count > 0) {
                cmbPuerto.SelectedIndex = 0;
                ConectPS.Enabled = true;
                DesconectPS.Enabled = false;

            }

        }

        private void ConectPS_Click(object sender, EventArgs e)
        {
            ConectPS.Enabled = false;
            DesconectPS.Enabled = true;
            // Activar panel 2
            panel2.Enabled = true; // activa selector de modos
            panel3.Enabled = false;
            panel4.Enabled = false;
            BtnAuto.Enabled = true;
            BtnManual.Enabled = true;


            try
            {
                PuertoSerie.PortName = cmbPuerto.Text;
                PuertoSerie.Open();
                


                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
           
        }

        private void DesconectPS_Click(object sender, EventArgs e)
        {
            ConectPS.Enabled = true;
            DesconectPS.Enabled = false;
            // Desactivar panel 2
            panel2.Enabled = false; // desactiva selector de modos
            panel3.Enabled = false;
            panel4.Enabled = false;
            BtnAuto.Enabled = false;
            BtnManual.Enabled = false;

            try
            {

                PuertoSerie.Close();
                

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void BtnAuto_Click(object sender, EventArgs e) // cambia a modo automatico
        {
            EnviarCaracter('a');
            panel1.Enabled = true; // se mantiene abierto el puerto serie
            panel2.Enabled = false; // se desactiva el selector para evitar confusiones
            panel3.Enabled = true; // se activa el modo automatico
            panel4.Enabled = false; // se mantiene desactivado el modo manual
            BtnAuto.Enabled = false;
            BtnManual.Enabled = false;
        }

        private void BtnManual_Click(object sender, EventArgs e) // cambia a modo manual
        {
            EnviarCaracter('b');
            panel1.Enabled = true; // se mantiene abierto el puerto serie
            panel2.Enabled = false; // se desactiva el selector para evitar confusiones
            panel3.Enabled = true; // se mantiene desactivado el modo automatico
            panel4.Enabled = true; // se activa el modo manual
            BtnAuto.Enabled = false;
            BtnManual.Enabled = false;
        }

        private void BtnDescA_Click(object sender, EventArgs e) // desactiva modo automatico
        {
            EnviarCaracter('s');
            panel1.Enabled = true; // se mantiene abierto el puerto serie
            panel2.Enabled = true; // se activa el selector 
            panel3.Enabled = true; // se desactiva el modo automatico
            panel4.Enabled = false; // se desactiva el modo manual
            BtnAuto.Enabled = true;
            BtnManual.Enabled = true;
        }

        private void BtnDescM_Click(object sender, EventArgs e) // desactiva modo manual
        {
            EnviarCaracter('s');
            panel1.Enabled = true; // se mantiene abierto el puerto serie
            panel2.Enabled = true; // se activa el selector 
            panel3.Enabled = false; // se desactiva el modo automatico
            panel4.Enabled = false; // se desactiva el modo manual
            BtnAuto.Enabled = true;
            BtnManual.Enabled = true;
        }

        private void BtnSalirSM_Click(object sender, EventArgs e)
        {
            panel1.Enabled = true; // se mantiene abierto el puerto serie
            panel2.Enabled = false; // se desactiva el selector 
            panel3.Enabled = false; // se desactiva el modo automatico
            panel4.Enabled = false; // se desactiva el modo manual
            BtnAuto.Enabled = false;
            BtnManual.Enabled = false;
        }

        private void TxbRespuestaA_TextChanged(object sender, EventArgs e)
        {
       

        }

        private void puertoSerie_DataReceived(object sender, SerialDataReceivedEventArgs e) //recibe datos del puerto serie 
        {
            if (panel3.Enabled == true)
            {
                while (PuertoSerie.IsOpen)
                {
                    try
                    {
                        respuesta = PuertoSerie.ReadLine();
                        TxbRespuestaA.Invoke(new MethodInvoker(delegate { TxbRespuestaA.Text = respuesta; }));

                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }

            }
           


        }

        private void BtnEncVen_Click(object sender, EventArgs e)
        {
            EnviarCaracter('c');
            BtnEncVen.Enabled = true;
            
        }

        

        private void EnviarCaracter(char caracter)
        {
            try
            {
                if (PuertoSerie.IsOpen)
                {
                    PuertoSerie.WriteLine(caracter.ToString());
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error al ejecutar comando", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void PuertoSerie_DataReceived_1(object sender, SerialDataReceivedEventArgs e)
        {
            if (panel3.Enabled)
            {
                while (PuertoSerie.IsOpen)
                {
                    try
                    {
                        respuesta = PuertoSerie.ReadLine();
                        this.Invoke(new MethodInvoker(delegate { TxbRespuestaA.Text = respuesta; }));
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }else if (panel4.Enabled)
            {
                while (PuertoSerie.IsOpen)
                {
                    try
                    {
                        respuesta = PuertoSerie.ReadLine();
                        this.Invoke(new MethodInvoker(delegate { TxbRespuestaA.Text = respuesta; }));
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }


        }

        private void TxbRespuestaM_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
