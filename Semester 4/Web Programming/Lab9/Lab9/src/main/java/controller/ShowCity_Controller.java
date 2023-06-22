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

@WebServlet(name = "showCity", value = "/show-city")
public class ShowCity_Controller extends HttpServlet {
    public ShowCity_Controller() {
        super();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        for (Cookie cookie : request.getCookies()) {
            if (cookie.getName().equals("user")) {
                List<City> cities = new DB_Manager().getCities();
                request.getSession().setAttribute("cities", cities);
                request.getRequestDispatcher("core/city-display/city-display.jsp").include(request, response);
                return;
            }
        }
        response.getWriter().println("Invalid request, need to log in");
    }
}
