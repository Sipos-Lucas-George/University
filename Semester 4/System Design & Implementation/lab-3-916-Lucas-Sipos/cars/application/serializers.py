from rest_framework import serializers
from .models import *


class CarSerializer(serializers.ModelSerializer):
    class Meta:
        model = Car
        fields = '__all__'


class BuyerSerializer(serializers.ModelSerializer):
    class Meta:
        model = Buyer
        fields = '__all__'


class DeliverySerializer(serializers.ModelSerializer):
    class Meta:
        model = DeliveryService
        fields = '__all__'
