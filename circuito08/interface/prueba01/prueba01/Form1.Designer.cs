namespace prueba01
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
            this.cambiarColor = new System.Windows.Forms.GroupBox();
            this.imprimir = new System.Windows.Forms.Label();
            this.cambiar = new System.Windows.Forms.Button();
            this.cambiarColor.SuspendLayout();
            this.SuspendLayout();
            // 
            // cambiarColor
            // 
            this.cambiarColor.Controls.Add(this.imprimir);
            this.cambiarColor.Controls.Add(this.cambiar);
            this.cambiarColor.Location = new System.Drawing.Point(97, 31);
            this.cambiarColor.Name = "cambiarColor";
            this.cambiarColor.Size = new System.Drawing.Size(533, 374);
            this.cambiarColor.TabIndex = 0;
            this.cambiarColor.TabStop = false;
            this.cambiarColor.Text = "Color";
            this.cambiarColor.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // imprimir
            // 
            this.imprimir.AutoSize = true;
            this.imprimir.Location = new System.Drawing.Point(224, 69);
            this.imprimir.Name = "imprimir";
            this.imprimir.Size = new System.Drawing.Size(46, 20);
            this.imprimir.TabIndex = 1;
            this.imprimir.Text = "Hola!";
            this.imprimir.Click += new System.EventHandler(this.label1_Click);
            // 
            // cambiar
            // 
            this.cambiar.Location = new System.Drawing.Point(208, 165);
            this.cambiar.Name = "cambiar";
            this.cambiar.Size = new System.Drawing.Size(117, 50);
            this.cambiar.TabIndex = 0;
            this.cambiar.Text = "Cambiar!";
            this.cambiar.UseVisualStyleBackColor = true;
            this.cambiar.Click += new System.EventHandler(this.cambiar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.cambiarColor);
            this.Name = "Form1";
            this.Text = "Form1";
            this.cambiarColor.ResumeLayout(false);
            this.cambiarColor.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox cambiarColor;
        private System.Windows.Forms.Button cambiar;
        private System.Windows.Forms.Label imprimir;
    }
}

