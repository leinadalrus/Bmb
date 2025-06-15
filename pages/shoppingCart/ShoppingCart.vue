<script setup lang="ts">
import { ref, computed } from 'vue'
import { type ProductCardMutationType } from '../(components)/ProductCard.vue'

defineProps<{
    shoppingCartList: ProductCardMutationType[]
}>()

defineEmits<{
    (e: 'undoChangeToShoppingCart', product: ProductCardMutationType): void
    (e: 'removeProductFromShoppingCart', product: ProductCardMutationType): void
}>() // Implicitly calls function

type ShoppingCartType = {
    id: number
    name: string
    price: number
    quantity: number
    paraphernalia: ProductCardMutationType[]
}

const cart = ref<ShoppingCartType[]>([])
const isPaymentModalActive = ref(false)

const total = computed(() => {
    return cart.value.reduce(
        (sumTotal, product) => sumTotal + product.price * product.quantity,
        0
    )
})
</script>

<template>
    <table>
        <thead>
            <tr>
                <th>Product name</th>
                <th>Quantity</th>
                <th>Price</th>
                <th>Total</th>
            </tr>
        </thead>

        <tbody>
            <tr v-for="product in shoppingCartList" v-bind:key="product.id">
                <td>{{ product.name }}</td>
                <td>
                    <input
                        type="number"
                        name=""
                        id=""
                        v-model.number="product.quantity"
                        min="1"
                        max="1"
                    />
                </td>
                <td>{{ product.price.toFixed(2) }}</td>
                <td>
                    <button
                        @click="
                            () => {
                                $emit('removeProductFromShoppingCart', product)
                            }
                        "
                    >
                        Remove from shopping cart
                    </button>
                </td>
            </tr>
        </tbody>
    </table>

    <span>{{ total }}</span>
    <button v-on:click="isPaymentModalActive = true">to Checkout?</button>
</template>
