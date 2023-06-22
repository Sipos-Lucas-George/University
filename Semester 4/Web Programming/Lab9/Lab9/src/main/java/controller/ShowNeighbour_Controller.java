package controller;

import domanin.City;
import domanin.DB_Manager;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.List;

@WebServlet(name = "showNeighbour", value = "/show-neighbour")
public class ShowNeighbour_Controller extends HttpServlet {
    public ShowNeighbour_Controller() {
        super();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        for (Cookie cookie : request.getCookies()) {
            if (cookie.getName().equals("user")) {
                var city_id = Integer.parseInt(request.getParameter("id"));
                List<City> cities = new DB_Manager().getNeighbouringCities(city_id);
                response.getWriter().println(cities);
                return;
            }
        }
        response.getWriter().println("Invalid request, need to log in");
    }
}
