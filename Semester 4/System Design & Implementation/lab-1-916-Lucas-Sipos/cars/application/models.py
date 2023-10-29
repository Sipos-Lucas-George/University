from django.db import models


class Car(models.Model):
    model = models.CharField(max_length=200)
    year = models.IntegerField()
    fuel_type = models.CharField(max_length=200)
    cc = models.CharField(max_length=200)
    hp = models.CharField(max_length=200)
    transmission_type = models.CharField(max_length=200)

    def __str__(self):
        return f"{self.id}.\t{self.model} {self.year} {self.fuel_type} {self.cc} {self.hp} {self.transmission_type}"
