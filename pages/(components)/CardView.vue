<script setup lang="ts">
import ProductCard, { type ProductCardMutationType } from './ProductCard.vue'

const productCards = shallowRef<ProductCardMutationType[]>()
</script>

<template>
    <section
        class="grid grid-cols-1 grid-rows-[repeat(auto-fit,_minmax(12.5rem,_1fr))] gap-4"
        v-for="i in productCards"
        v-bind:key="i.id"
    >
        <ProductCard
            :name="i.name"
            :description="i.description"
            :synopsis="i.synopsis"
            :producer="i.producer"
            :distributor="i.distributor"
            :image="i.image"
            :tags="i.tags"
            :price="i.price"
        />
    </section>
</template>
