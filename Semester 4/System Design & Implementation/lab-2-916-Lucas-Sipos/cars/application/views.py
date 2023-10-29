from rest_framework.generics import ListAPIView
from rest_framework.views import APIView
from .models import Car, Buyer, Delivery
from .serializers import CarSerializer, BuyerSerializer, DeliverySerializer
from rest_framework.response import Response
from rest_framework import status


class CarList(ListAPIView):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.__queryset = Car.objects.all()
        self.__serializer_class = CarSerializer

    @property
    def queryset(self):
        return self.__queryset

    @property
    def serializer_class(self):
        return self.__serializer_class

    def get(self, request, id=None):
        if id:
            entity = self.__queryset.get(id=id)
            serializer = self.__serializer_class(entity)

            events = Buyer.objects.all().filter(car=entity.id)
            events_serializer = BuyerSerializer(events, many=True)
            return Response({"status": "success", "cars": serializer.data, "buyers": events_serializer.data},
                            status=status.HTTP_200_OK)
        year = request.query_params.get('year', None)
        if year:
            self.__queryset = self.__queryset.filter(year__gte=year)
        if id:
            car = self.__queryset.get(id=id)
            serializer = self.__serializer_class(car)
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        items = self.__queryset
        serializer = self.__serializer_class(items, many=True)
        return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)

    def post(self, request):
        serializer = self.__serializer_class(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_201_CREATED)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def patch(self, request, id=None):
        item = self.__queryset.get(id=id)
        serializer = self.__serializer_class(item, data=request.data, partial=True)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, id=None):
        if not id:
            return Response({"status": "error", "data": "ID not specified"}, status=status.HTTP_400_BAD_REQUEST)
        item = self.__queryset.get(id=id)
        item.delete()
        return Response({"status": "success", "data": "Item deleted"}, status=status.HTTP_200_OK)


class BuyerList(APIView):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.__queryset = Buyer.objects.all()
        self.__serializer_class = BuyerSerializer

    @property
    def queryset(self):
        return self.__queryset

    @property
    def serializer_class(self):
        return self.__serializer_class

    def get(self, request, id=None):
        if id:
            car = self.__queryset.get(id=id)
            serializer = self.__serializer_class(car)
            events = Car.objects.all().filter(id=car.id)
            events_serializer = CarSerializer(events, many=True)
            return Response({"status": "success", "buyers": serializer.data, "cars": events_serializer.data},
                            status=status.HTTP_200_OK)
        items = self.__queryset
        serializer = self.__serializer_class(items, many=True)
        return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)

    def post(self, request):
        serializer = self.__serializer_class(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_201_CREATED)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def patch(self, request, id=None):
        item = self.__queryset.get(id=id)
        serializer = self.__serializer_class(item, data=request.data, partial=True)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, id=None):
        if not id:
            return Response({"status": "error", "data": "ID not specified"}, status=status.HTTP_400_BAD_REQUEST)
        item = self.__queryset.get(id=id)
        item.delete()
        return Response({"status": "success", "data": "Item deleted"}, status=status.HTTP_200_OK)


class DeliveryList(APIView):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.__queryset = Delivery.objects.all()
        self.__serializer_class = DeliverySerializer

    @property
    def queryset(self):
        return self.__queryset

    @property
    def serializer_class(self):
        return self.__serializer_class

    def get(self, request, id=None):
        if id:
            car = self.__queryset.get(id=id)
            serializer = self.__serializer_class(car)
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        items = self.__queryset
        serializer = self.__serializer_class(items, many=True)
        return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)

    def post(self, request):
        serializer = self.__serializer_class(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_201_CREATED)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def patch(self, request, id=None):
        item = self.__queryset.get(id=id)
        serializer = self.__serializer_class(item, data=request.data, partial=True)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, id=None):
        if not id:
            return Response({"status": "error", "data": "ID not specified"}, status=status.HTTP_400_BAD_REQUEST)
        item = self.__queryset.get(id=id)
        item.delete()
        return Response({"status": "success", "data": "Item deleted"}, status=status.HTTP_200_OK)
