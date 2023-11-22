namespace prueba01
{
    partial class COM
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.cmbPuerto = new System.Windows.Forms.ComboBox();
            this.btnConectar = new System.Windows.Forms.Button();
            this.btnDesconectar = new System.Windows.Forms.Button();
            this.txbEnviar = new System.Windows.Forms.TextBox();
            this.txbRespuesta = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnEnviar = new System.Windows.Forms.Button();
            this.btnRecibir = new System.Windows.Forms.Button();
            this.puertoSerie = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(92, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Puerto: ";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // cmbPuerto
            // 
            this.cmbPuerto.FormattingEnabled = true;
            this.cmbPuerto.Location = new System.Drawing.Point(171, 26);
            this.cmbPuerto.Name = "cmbPuerto";
            this.cmbPuerto.Size = new System.Drawing.Size(210, 28);
            this.cmbPuerto.TabIndex = 1;
            // 
            // btnConectar
            // 
            this.btnConectar.Location = new System.Drawing.Point(387, 26);
            this.btnConectar.Name = "btnConectar";
            this.btnConectar.Size = new System.Drawing.Size(94, 36);
            this.btnConectar.TabIndex = 2;
            this.btnConectar.Text = "Conectar";
            this.btnConectar.UseVisualStyleBackColor = true;
            this.btnConectar.Click += new System.EventHandler(this.btnConectar_Click);
            // 
            // btnDesconectar
            // 
            this.btnDesconectar.Location = new System.Drawing.Point(487, 26);
            this.btnDesconectar.Name = "btnDesconectar";
            this.btnDesconectar.Size = new System.Drawing.Size(116, 36);
            this.btnDesconectar.TabIndex = 3;
            this.btnDesconectar.Text = "Desconectar";
            this.btnDesconectar.UseVisualStyleBackColor = true;
            this.btnDesconectar.Click += new System.EventHandler(this.btnDesconectar_Click);
            // 
            // txbEnviar
            // 
            this.txbEnviar.Location = new System.Drawing.Point(171, 82);
            this.txbEnviar.Name = "txbEnviar";
            this.txbEnviar.Size = new System.Drawing.Size(432, 26);
            this.txbEnviar.TabIndex = 4;
            // 
            // txbRespuesta
            // 
            this.txbRespuesta.Location = new System.Drawing.Point(171, 161);
            this.txbRespuesta.Multiline = true;
            this.txbRespuesta.Name = "txbRespuesta";
            this.txbRespuesta.Size = new System.Drawing.Size(543, 177);
            this.txbRespuesta.TabIndex = 5;
            this.txbRespuesta.TextChanged += new System.EventHandler(this.txbRespuesta_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(92, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(68, 20);
            this.label2.TabIndex = 6;
            this.label2.Text = "Ingresar";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(78, 161);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 20);
            this.label3.TabIndex = 7;
            this.label3.Text = "Respuesta";
            // 
            // btnEnviar
            // 
            this.btnEnviar.Location = new System.Drawing.Point(528, 114);
            this.btnEnviar.Name = "btnEnviar";
            this.btnEnviar.Size = new System.Drawing.Size(75, 37);
            this.btnEnviar.TabIndex = 8;
            this.btnEnviar.Text = "Enviar";
            this.btnEnviar.UseVisualStyleBackColor = true;
            this.btnEnviar.Click += new System.EventHandler(this.btnEnviar_Click);
            // 
            // btnRecibir
            // 
            this.btnRecibir.Location = new System.Drawing.Point(639, 353);
            this.btnRecibir.Name = "btnRecibir";
            this.btnRecibir.Size = new System.Drawing.Size(75, 27);
            this.btnRecibir.TabIndex = 9;
            this.btnRecibir.Text = "Recibir";
            this.btnRecibir.UseVisualStyleBackColor = true;
            // 
            // puertoSerie
            // 
            this.puertoSerie.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.puertoSerie_DataReceived);
            // 
            // COM
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnRecibir);
            this.Controls.Add(this.btnEnviar);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txbRespuesta);
            this.Controls.Add(this.txbEnviar);
            this.Controls.Add(this.btnDesconectar);
            this.Controls.Add(this.btnConectar);
            this.Controls.Add(this.cmbPuerto);
            this.Controls.Add(this.label1);
            this.Name = "COM";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.COM_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmbPuerto;
        private System.Windows.Forms.Button btnConectar;
        private System.Windows.Forms.Button btnDesconectar;
        private System.Windows.Forms.TextBox txbEnviar;
        private System.Windows.Forms.TextBox txbRespuesta;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnEnviar;
        private System.Windows.Forms.Button btnRecibir;
        private System.IO.Ports.SerialPort puertoSerie;
    }
}

