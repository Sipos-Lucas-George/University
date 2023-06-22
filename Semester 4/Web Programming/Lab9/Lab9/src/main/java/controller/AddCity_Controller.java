package controller;

import domanin.DB_Manager;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class AddCity_Controller extends HttpServlet {
    public AddCity_Controller() {
        super();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) {
        new DB_Manager().addCity(request.getParameter("name"));
    }
}
