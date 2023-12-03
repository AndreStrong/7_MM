namespace InterfazPFinal
{
    partial class Form1
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.InstConec = new System.Windows.Forms.Label();
            this.DesconectPS = new System.Windows.Forms.Button();
            this.ConectPS = new System.Windows.Forms.Button();
            this.cmbPuerto = new System.Windows.Forms.ComboBox();
            this.PuertoLabel = new System.Windows.Forms.Label();
            this.Bloque1txt = new System.Windows.Forms.Label();
            this.Bloque2txt = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.BtnSalirSM = new System.Windows.Forms.Button();
            this.BtnManual = new System.Windows.Forms.Button();
            this.BtnAuto = new System.Windows.Forms.Button();
            this.InstModo = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.BtnDescA = new System.Windows.Forms.Button();
            this.RespuestaLabel = new System.Windows.Forms.Label();
            this.TxbRespuestaA = new System.Windows.Forms.TextBox();
            this.Bloque4txt = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.BtnEncVen = new System.Windows.Forms.Button();
            this.PuertoSerie = new System.IO.Ports.SerialPort(this.components);
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.InstConec);
            this.panel1.Controls.Add(this.DesconectPS);
            this.panel1.Controls.Add(this.ConectPS);
            this.panel1.Controls.Add(this.cmbPuerto);
            this.panel1.Controls.Add(this.PuertoLabel);
            this.panel1.Location = new System.Drawing.Point(18, 55);
            this.panel1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1164, 77);
            this.panel1.TabIndex = 0;
            // 
            // InstConec
            // 
            this.InstConec.AutoSize = true;
            this.InstConec.Location = new System.Drawing.Point(614, 17);
            this.InstConec.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.InstConec.Name = "InstConec";
            this.InstConec.Size = new System.Drawing.Size(524, 40);
            this.InstConec.TabIndex = 4;
            this.InstConec.Text = "Conexion: Elige el puerto serie al que deseas conectarte y pulsa conectar\r\nDescon" +
    "exion: Pulsa desconectar\r\n";
            // 
            // DesconectPS
            // 
            this.DesconectPS.Location = new System.Drawing.Point(462, 17);
            this.DesconectPS.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.DesconectPS.Name = "DesconectPS";
            this.DesconectPS.Size = new System.Drawing.Size(123, 35);
            this.DesconectPS.TabIndex = 3;
            this.DesconectPS.Text = "Desconectar";
            this.DesconectPS.UseVisualStyleBackColor = true;
            this.DesconectPS.Click += new System.EventHandler(this.DesconectPS_Click);
            // 
            // ConectPS
            // 
            this.ConectPS.Location = new System.Drawing.Point(318, 17);
            this.ConectPS.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.ConectPS.Name = "ConectPS";
            this.ConectPS.Size = new System.Drawing.Size(112, 35);
            this.ConectPS.TabIndex = 2;
            this.ConectPS.Text = "Conectar";
            this.ConectPS.UseVisualStyleBackColor = true;
            this.ConectPS.Click += new System.EventHandler(this.ConectPS_Click);
            // 
            // cmbPuerto
            // 
            this.cmbPuerto.FormattingEnabled = true;
            this.cmbPuerto.Location = new System.Drawing.Point(96, 17);
            this.cmbPuerto.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.cmbPuerto.Name = "cmbPuerto";
            this.cmbPuerto.Size = new System.Drawing.Size(180, 28);
            this.cmbPuerto.TabIndex = 1;
            // 
            // PuertoLabel
            // 
            this.PuertoLabel.AutoSize = true;
            this.PuertoLabel.Location = new System.Drawing.Point(26, 22);
            this.PuertoLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.PuertoLabel.Name = "PuertoLabel";
            this.PuertoLabel.Size = new System.Drawing.Size(60, 20);
            this.PuertoLabel.TabIndex = 0;
            this.PuertoLabel.Text = "Puerto:";
            // 
            // Bloque1txt
            // 
            this.Bloque1txt.AutoSize = true;
            this.Bloque1txt.Location = new System.Drawing.Point(18, 14);
            this.Bloque1txt.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.Bloque1txt.Name = "Bloque1txt";
            this.Bloque1txt.Size = new System.Drawing.Size(75, 20);
            this.Bloque1txt.TabIndex = 1;
            this.Bloque1txt.Text = "Conexion";
            // 
            // Bloque2txt
            // 
            this.Bloque2txt.AutoSize = true;
            this.Bloque2txt.Location = new System.Drawing.Point(18, 162);
            this.Bloque2txt.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.Bloque2txt.Name = "Bloque2txt";
            this.Bloque2txt.Size = new System.Drawing.Size(134, 20);
            this.Bloque2txt.TabIndex = 2;
            this.Bloque2txt.Text = "Selector de modo";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.BtnSalirSM);
            this.panel2.Controls.Add(this.BtnManual);
            this.panel2.Controls.Add(this.BtnAuto);
            this.panel2.Controls.Add(this.InstModo);
            this.panel2.Location = new System.Drawing.Point(18, 205);
            this.panel2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1164, 154);
            this.panel2.TabIndex = 3;
            // 
            // BtnSalirSM
            // 
            this.BtnSalirSM.Location = new System.Drawing.Point(522, 69);
            this.BtnSalirSM.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BtnSalirSM.Name = "BtnSalirSM";
            this.BtnSalirSM.Size = new System.Drawing.Size(156, 52);
            this.BtnSalirSM.TabIndex = 8;
            this.BtnSalirSM.Text = "Salir del Selector";
            this.BtnSalirSM.UseVisualStyleBackColor = true;
            this.BtnSalirSM.Click += new System.EventHandler(this.BtnSalirSM_Click);
            // 
            // BtnManual
            // 
            this.BtnManual.Location = new System.Drawing.Point(768, 62);
            this.BtnManual.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BtnManual.Name = "BtnManual";
            this.BtnManual.Size = new System.Drawing.Size(219, 69);
            this.BtnManual.TabIndex = 6;
            this.BtnManual.Text = "Modo Manual";
            this.BtnManual.UseVisualStyleBackColor = true;
            this.BtnManual.Click += new System.EventHandler(this.BtnManual_Click);
            // 
            // BtnAuto
            // 
            this.BtnAuto.Location = new System.Drawing.Point(202, 62);
            this.BtnAuto.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BtnAuto.Name = "BtnAuto";
            this.BtnAuto.Size = new System.Drawing.Size(228, 69);
            this.BtnAuto.TabIndex = 5;
            this.BtnAuto.Text = "Modo Automatico";
            this.BtnAuto.UseVisualStyleBackColor = true;
            this.BtnAuto.Click += new System.EventHandler(this.BtnAuto_Click);
            // 
            // InstModo
            // 
            this.InstModo.AutoSize = true;
            this.InstModo.Location = new System.Drawing.Point(314, 15);
            this.InstModo.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.InstModo.Name = "InstModo";
            this.InstModo.Size = new System.Drawing.Size(563, 20);
            this.InstModo.TabIndex = 4;
            this.InstModo.Text = "Para poder seleccionar un modo pulsa el boton con el nombre correspondiente\r\n";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.BtnDescA);
            this.panel3.Controls.Add(this.RespuestaLabel);
            this.panel3.Controls.Add(this.TxbRespuestaA);
            this.panel3.Location = new System.Drawing.Point(18, 384);
            this.panel3.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1164, 151);
            this.panel3.TabIndex = 8;
            // 
            // BtnDescA
            // 
            this.BtnDescA.Location = new System.Drawing.Point(137, 72);
            this.BtnDescA.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BtnDescA.Name = "BtnDescA";
            this.BtnDescA.Size = new System.Drawing.Size(136, 35);
            this.BtnDescA.TabIndex = 7;
            this.BtnDescA.Text = "Desconectar";
            this.BtnDescA.UseVisualStyleBackColor = true;
            this.BtnDescA.Click += new System.EventHandler(this.BtnDescA_Click);
            // 
            // RespuestaLabel
            // 
            this.RespuestaLabel.AutoSize = true;
            this.RespuestaLabel.Location = new System.Drawing.Point(38, 24);
            this.RespuestaLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.RespuestaLabel.Name = "RespuestaLabel";
            this.RespuestaLabel.Size = new System.Drawing.Size(91, 20);
            this.RespuestaLabel.TabIndex = 2;
            this.RespuestaLabel.Text = "Respuesta:";
            // 
            // TxbRespuestaA
            // 
            this.TxbRespuestaA.Location = new System.Drawing.Point(137, 21);
            this.TxbRespuestaA.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.TxbRespuestaA.Multiline = true;
            this.TxbRespuestaA.Name = "TxbRespuestaA";
            this.TxbRespuestaA.ReadOnly = true;
            this.TxbRespuestaA.Size = new System.Drawing.Size(961, 41);
            this.TxbRespuestaA.TabIndex = 1;
            this.TxbRespuestaA.TextChanged += new System.EventHandler(this.TxbRespuestaA_TextChanged);
            // 
            // Bloque4txt
            // 
            this.Bloque4txt.AutoSize = true;
            this.Bloque4txt.Location = new System.Drawing.Point(20, 24);
            this.Bloque4txt.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.Bloque4txt.Name = "Bloque4txt";
            this.Bloque4txt.Size = new System.Drawing.Size(105, 20);
            this.Bloque4txt.TabIndex = 3;
            this.Bloque4txt.Text = "Modo Manual";
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.Bloque4txt);
            this.panel4.Controls.Add(this.BtnEncVen);
            this.panel4.Location = new System.Drawing.Point(22, 545);
            this.panel4.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(1160, 68);
            this.panel4.TabIndex = 9;
            // 
            // BtnEncVen
            // 
            this.BtnEncVen.Location = new System.Drawing.Point(144, 17);
            this.BtnEncVen.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BtnEncVen.Name = "BtnEncVen";
            this.BtnEncVen.Size = new System.Drawing.Size(201, 35);
            this.BtnEncVen.TabIndex = 1;
            this.BtnEncVen.Text = "ON/OFF";
            this.BtnEncVen.UseVisualStyleBackColor = true;
            this.BtnEncVen.Click += new System.EventHandler(this.BtnEncVen_Click);
            // 
            // PuertoSerie
            // 
            this.PuertoSerie.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.PuertoSerie_DataReceived_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1200, 1040);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.Bloque2txt);
            this.Controls.Add(this.Bloque1txt);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.panel4);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label Bloque1txt;
        private System.Windows.Forms.Button DesconectPS;
        private System.Windows.Forms.Button ConectPS;
        private System.Windows.Forms.ComboBox cmbPuerto;
        private System.Windows.Forms.Label PuertoLabel;
        private System.Windows.Forms.Label InstConec;
        private System.Windows.Forms.Label Bloque2txt;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button BtnManual;
        private System.Windows.Forms.Button BtnAuto;
        private System.Windows.Forms.Label InstModo;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label RespuestaLabel;
        private System.Windows.Forms.TextBox TxbRespuestaA;
        private System.Windows.Forms.Label Bloque4txt;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Button BtnEncVen;
        private System.IO.Ports.SerialPort PuertoSerie;
        private System.Windows.Forms.Button BtnDescA;
        private System.Windows.Forms.Button BtnSalirSM;
    }
}

