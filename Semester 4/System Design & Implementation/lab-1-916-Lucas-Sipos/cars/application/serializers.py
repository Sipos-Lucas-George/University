from rest_framework import serializers
from .models import Car


class CarSerializer(serializers.ModelSerializer):
    class Meta:
        model = Car
        fields = (
            'id',
            'model',
            'year',
            'fuel_type',
            'cc',
            'hp',
            'transmission_type'
        )
