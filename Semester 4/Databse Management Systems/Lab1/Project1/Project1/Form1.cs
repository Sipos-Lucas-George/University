using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project1
{
    public partial class Form1 : Form
    {
        private int businessID = -1;
        private int adminID = -1;
        public Form1()
        {
            InitializeComponent();
            populateBusiness();
        }

        private void clearData()
        {
            textBox_telephone.Clear();
            textBox_businessName.Clear();
            textBox_fullName.Clear();
            textBox_officeAddr.Clear();
        }
        
        public void populateBusiness()
        {
            var connect = new SqlConnection("Data Source=localhost;Initial Catalog=Database;Integrated security=true");
            connect.Open();
            var cmd = new SqlCommand("select * from TransportBusiness", connect);
            DataTable dataTable = new DataTable();
            var adapter = new SqlDataAdapter(cmd);
            adapter.Fill(dataTable);
            dataGridView_business.DataSource = dataTable;
            dataGridView_business.ReadOnly = true;
            cmd.ExecuteNonQuery();
            connect.Close();
        }

        public void populateAdmin()
        {
            var connect = new SqlConnection("Data Source=localhost;Initial Catalog=Database;Integrated security=true");
            connect.Open();
            var cmd = new SqlCommand("select * from Administrator where businessID = @id", connect);
            cmd.Parameters.AddWithValue("@id", businessID);
            DataTable dt = new DataTable();
            var adapter = new SqlDataAdapter(cmd);
            adapter.Fill(dt);
            dataGridView_admin.DataSource = dt;
            dataGridView_admin.ReadOnly = true;
            cmd.ExecuteNonQuery();
            connect.Close();
        }
        
        private void dataGridView_business_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            clearData();
            dataGridView_business.CurrentRow.Selected = true;
            businessID = int.Parse(dataGridView_business.Rows[e.RowIndex].Cells["id"].Value.ToString());
            textBox_businessName.Text = businessID.ToString();
            if (dataGridView_business.SelectedRows.Count > 0)
                groupBox1.Enabled = true;
            var connect = new SqlConnection("Data Source=localhost;Initial Catalog=Database;Integrated security=true");
            connect.Open();
            var cmd = new SqlCommand("select * from Administrator where businessID = @id", connect);
            cmd.Parameters.AddWithValue("@id", businessID);
            DataTable dt = new DataTable();
            var adapter = new SqlDataAdapter(cmd);
            adapter.Fill(dt);
            dataGridView_admin.DataSource = dt;
            dataGridView_admin.ReadOnly = true;
            cmd.ExecuteNonQuery();
            connect.Close();
        }

        private void dataGridView_admin_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            clearData();
            adminID = int.Parse(dataGridView_admin.Rows[e.RowIndex].Cells["id"].Value.ToString());
            textBox_businessName.Text = businessID.ToString();
            textBox_fullName.Text = dataGridView_admin.Rows[e.RowIndex].Cells["fullName"].Value.ToString();
            textBox_officeAddr.Text = dataGridView_admin.Rows[e.RowIndex].Cells["officeAddress"].Value.ToString();
            textBox_telephone.Text = dataGridView_admin.Rows[e.RowIndex].Cells["telephoneNumber"].Value.ToString();
        }

        private void button_add_Click(object sender, EventArgs e)
        {
            var connect = new SqlConnection("Data Source=localhost;Initial Catalog=Database;Integrated security=true");
            connect.Open();
            var cmd = new SqlCommand("insert into Administrator values (@businessID, @fullName, @telephoneNumber, @officeAddress)", connect);
            cmd.Parameters.AddWithValue("@businessID", businessID);
            cmd.Parameters.AddWithValue("@fullName", textBox_fullName.Text);
            cmd.Parameters.AddWithValue("@telephoneNumber", textBox_telephone.Text);
            cmd.Parameters.AddWithValue("@officeAddress", textBox_officeAddr.Text);
            cmd.ExecuteNonQuery();
            clearData();
            populateAdmin();
            connect.Close();
            MessageBox.Show("Successfully Inserted");
        }

        private void button_update_Click(object sender, EventArgs e)
        {
            var connect = new SqlConnection("Data Source=localhost;Initial Catalog=Database;Integrated security=true");
            connect.Open();
            var cmd = new SqlCommand("update Administrator set fullName=@fullName, telephoneNumber=@telephoneNumber, officeAddress=@officeAddress where id=@adminID", connect);
            cmd.Parameters.AddWithValue("@adminID", adminID);
            cmd.Parameters.AddWithValue("@fullName", textBox_fullName.Text);
            cmd.Parameters.AddWithValue("@telephoneNumber", textBox_telephone.Text);
            cmd.Parameters.AddWithValue("@officeAddress", textBox_officeAddr.Text);
            cmd.ExecuteNonQuery();
            clearData();
            populateAdmin();
            connect.Close();
            MessageBox.Show("Successfully Updated");
        }

        private void button_delete_Click(object sender, EventArgs e)
        {
            var connect = new SqlConnection("Data Source=localhost;Initial Catalog=Database;Integrated security=true");
            connect.Open();
            var cmd = new SqlCommand("delete from Administrator where id=@adminID", connect);
            cmd.Parameters.AddWithValue("@adminID", adminID);
            cmd.ExecuteNonQuery();
            clearData();
            populateAdmin();
            connect.Close();
            MessageBox.Show("Successfully Deleted");
        }
    }
}