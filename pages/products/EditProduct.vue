<script setup lang="ts">
import type { ProductCardMutationType } from '../(components)/ProductCard.vue'

defineProps<{
    products: ProductCardMutationType[]
}>()

defineEmits<{
    (e: 'saveProductForm', product: ProductCardMutationType): void
    (e: 'discardProductForm', product: ProductCardMutationType): void
}>() // Implicitly calls function
</script>

<template>
    <form
        action=""
        method="post"
        v-for="product in products"
        :key="product.id"
        @submit="$emit('saveProductForm', product)"
    >
        <label for="name">Product name</label>
        <input type="text" :name="product.name" id="" />

        <label for="description">Description</label>
        <input type="text" :name="product.description" id="" />

        <label for="synopsis">Synopsis</label>
        <input type="text" :name="product.synopsis" id="" />

        <label for="price">Pricing</label>
        <input type="number" :name="product.price.toString" id="" />

        <label for="quantity">Quantity</label>
        <input type="number" :name="product.quantity.toString" id="" />

        <label for="tags">Tags</label>
        <option value="tags">
            <select name="game" id="">
                Games
            </select>
            <select name="comic" id="">
                Comics
            </select>
            <select name="illustration" id="">
                Illustrations
            </select>
            <select name="accessory" id="">
                Accessories
            </select>
            <select name="video" id="">
                Videos
            </select>
            <select name="voice" id="">
                Voice
            </select>
            <select name="music" id="">
                Music
            </select>
            <select name="tool" id="">
                Tools
            </select>
        </option>

        <button type="submit">Save</button>

        <button type="button" @click="$emit('discardProductForm', product)">
            Discard
        </button>
    </form>
</template>
