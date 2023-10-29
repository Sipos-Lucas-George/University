from django.db import models


class Car(models.Model):
    transmission_types = [
        ["M", "Manual"],
        ["A", "Automatic"],
        ["C", "CVT"],
    ]
    fuel_types = [
        ["G", "Gasoline"],
        ["D", "Diesel"],
        ["BD", "Bio-Diesel"],
        ["E", "Ethanol"],
    ]
    model = models.CharField(max_length=200)
    year = models.IntegerField()
    fuel_type = models.CharField(choices=fuel_types, max_length=200)
    cc = models.CharField(max_length=200)
    hp = models.CharField(max_length=200)
    transmission_type = models.CharField(choices=transmission_types, max_length=200)

    def __str__(self):
        return f"{self.id}.\t{self.model} {self.year} {self.fuel_type} {self.cc} {self.hp} {self.transmission_type}"


class Buyer(models.Model):
    sex_options = [
        ["M", "Male"],
        ["F", "Female"],
        ["D", "Disabled"],
        ["N", "Do not want to answer"],
    ]
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)
    age = models.IntegerField()
    sex = models.CharField(choices=sex_options, max_length=20)
    car = models.ForeignKey(Car, on_delete=models.DO_NOTHING)


class Delivery(models.Model):
    delivery_person = models.CharField(blank=True, max_length=100)
    fee = models.IntegerField(blank=True)
    date = models.DateField()
    pickup = models.BooleanField()
    details = models.TextField(max_length=300)
