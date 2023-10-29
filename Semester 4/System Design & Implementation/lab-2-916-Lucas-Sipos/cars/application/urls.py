from django.urls import path
from rest_framework.urlpatterns import format_suffix_patterns
from .views import *


urlpatterns = [
    path('cars/', CarList.as_view()),
    path('cars/<int:id>/', CarList.as_view()),

    path('buyers/', BuyerList.as_view()),
    path('buyers/<int:id>/', BuyerList.as_view()),

    path('delivs/', DeliveryList.as_view()),
    path('delivs/<int:id>/', DeliveryList.as_view()),
]

urlpatterns = format_suffix_patterns(urlpatterns)
