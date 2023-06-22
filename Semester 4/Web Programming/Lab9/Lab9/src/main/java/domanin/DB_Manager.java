package domanin;

import com.mysql.jdbc.Driver;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class DB_Manager {
    private static final String connection_url = "jdbc:mysql://localhost:3306/lab9_web";
    private static final String name = "lucas";
    private static final String password = "password";

    public DB_Manager() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    public User getUserFromName(String username) {
        User user = null;
        String statement = "select * from users where username='" + username + "'";
        try (var connection = DriverManager.getConnection(connection_url, name, password);
             var preparedStatement = connection.prepareStatement(statement);
             var rs = preparedStatement.executeQuery()) {
            if (rs.next())
                user = new User(rs.getInt("id"), rs.getString("username"), rs.getString("password"));
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return user;
    }

    public User authenticate(String username, String password) {
        User user = getUserFromName(username);
        if (user != null && user.getPassword().equals(password))
            return user;
        return null;
    }

    public List<City> getCities() {
        List<City> cities = new ArrayList<>();
        String statement = "select * from cities";
        try (var connection = DriverManager.getConnection(connection_url, name, password);
             var preparedStatement = connection.prepareStatement(statement);
             var rs = preparedStatement.executeQuery()) {
            while (rs.next())
                cities.add(new City(rs.getInt("id"), rs.getString("name")));
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return cities;
    }

    public List<City> getNeighbouringCities(int city_id) {
        List<City> cities = new ArrayList<>();
        String statement = "select c.* from neighboring_cities nc join cities c on c.id=nc.city_id or nc.neighbour_id = c.id where (nc.city_id=" + city_id + " or nc.neighbour_id=" + city_id + ") and c.id!=" + city_id;
        try (var connection = DriverManager.getConnection(connection_url, name, password);
             var preparedStatement = connection.prepareStatement(statement);
             var rs = preparedStatement.executeQuery()) {
            while (rs.next())
                cities.add(new City(rs.getInt("id"), rs.getString("name")));
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return cities;
    }

    public void addCity(String name) {
        String statement = "insert into cities (name) values ('" + name + "')";
        try {
            var connection = DriverManager.getConnection(connection_url, name, password);
            var preparedStatement = connection.prepareStatement(statement);
            preparedStatement.executeQuery();
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
    }

    public void addCityNeighbour(int city, int neighbour) throws Exception {
        if (city == neighbour) {
            throw new Exception("Duplicate city");
        }
        if (city > neighbour) {
            city = (neighbour + city) - (neighbour = city);
        }
        String statement = "insert into neighboring_cities (city_id, neighbour_id) values (" + city + "," + neighbour + ")";
        try {
            var connection = DriverManager.getConnection(connection_url, name, password);
            var preparedStatement = connection.prepareStatement(statement);
            preparedStatement.executeQuery();
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
    }
}
