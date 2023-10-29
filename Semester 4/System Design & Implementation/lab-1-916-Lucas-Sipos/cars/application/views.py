from rest_framework.views import APIView
from .models import Car
from .serializers import CarSerializer
from rest_framework.response import Response
from rest_framework import status
from django.shortcuts import get_object_or_404


class CarList(APIView):
    queryset = Car.objects.all()
    serializer_class = CarSerializer

    def get(self, request, id=None):
        if id:
            car = Car.objects.get(id=id)
            serializer = CarSerializer(car)
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        items = Car.objects.all()
        serializer = CarSerializer(items, many=True)
        return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)

    def post(self, request):
        serializer = CarSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_201_CREATED)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def patch(self, request, id=None):
        item = Car.objects.get(id=id)
        serializer = CarSerializer(item, data=request.data, partial=True)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, id=None):
        item = get_object_or_404(Car, id=id)
        item.delete()
        return Response({"status": "success", "data": "Item deleted"}, status=status.HTTP_200_OK)
