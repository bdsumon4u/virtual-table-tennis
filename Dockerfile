FROM getmeili/meilisearch:latest
EXPOSE 7700

FROM redis:5-alpine
EXPOSE 6379
