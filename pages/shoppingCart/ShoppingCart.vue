<script setup lang="ts">
import PaymentModal from '../payments/PaymentModal.vue'

interface IShoppingCart {
    id: number
    name: string
    price: number
    quantity: number
}

const cart = ref<IShoppingCart[]>([])
const isPaymentModalActive = ref(false)
const total = computed(() => {
    return cart.value.reduce(
        (sumTotal, product) => sumTotal + product.price * product.quantity,
        0
    )
})

function removeFromShoppingCart(id: number) {
    cart.value = cart.value.filter((i) => i.id != id)
}

function updateShoppingCart(shoppingCart: IShoppingCart) {
    if (shoppingCart.quantity < 1) removeFromShoppingCart(shoppingCart.id)
}

function handlePaymentSuccess() {
    // TODO: Stripe/PayPal API checkout-payment throughput processing here
}
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
            <tr v-for="item in cart" v-bind:key="item.id">
                <td>{{ item.name }}</td>
                <td>
                    <input
                        type="number"
                        name=""
                        id=""
                        v-model.number="item.quantity"
                        min="1"
                        max="1"
                        v-on:change="updateShoppingCart(item)"
                    />
                </td>
                <td>{{ item.price.toFixed(2) }}</td>
                <td>
                    <button v-on:click="removeFromShoppingCart(item.id)">
                        Remove from shopping cart
                    </button>
                </td>
            </tr>
        </tbody>
    </table>

    <span>{{ total }}</span>
    <button v-on:click="isPaymentModalActive = true">to Checkout?</button>

    <PaymentModal
        v-if="isPaymentModalActive == true"
        v-bind:quantity="total"
        v-on:close="isPaymentModalActive = false"
        v-on:succession="handlePaymentSuccess()"
    />
</template>
