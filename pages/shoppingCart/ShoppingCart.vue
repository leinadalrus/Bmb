<script setup lang="ts">
interface IShoppingCart {
    id: number
    name: string
    price: number
    quantity: number
}

const cart = ref<IShoppingCart[]>([])
const isPaymentModalActive = ref(false)
const total = computed(() => {
    cart.value.reduce(
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

function handlePaymentModal() {
    isPaymentModalActive.value = false
}
</script>

<template></template>
