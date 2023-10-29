from django.urls import path
from rest_framework.urlpatterns import format_suffix_patterns
from .views import CarList


urlpatterns = [
    path('cars/', CarList.as_view()),
    path('cars/<int:id>/', CarList.as_view()),
]

urlpatterns = format_suffix_patterns(urlpatterns)
