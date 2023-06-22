package controller;

import domanin.DB_Manager;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

public class AddNeighbour_Controller extends HttpServlet {
    public AddNeighbour_Controller() {
        super();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            new DB_Manager().addCityNeighbour(Integer.parseInt(request.getParameter("city_id")),
                    Integer.parseInt(request.getParameter("neighbour_id")));
        } catch (Exception e) {
            response.sendError(418, e.getMessage());
        }
    }
}
